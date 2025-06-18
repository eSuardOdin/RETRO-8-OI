// 🖼️ Fonction de dessin de la framebuffer
static gboolean on_draw(GtkWidget *widget, cairo_t *cr, gpointer data) {
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_data(
        framebuffer,
        GDK_COLORSPACE_RGB,
        FALSE,               // Pas d'alpha
        8,                   // 8 bits par composante
        FB_WIDTH,
        FB_HEIGHT,
        FB_WIDTH * 3,        // rowstride
        NULL, NULL           // Pas de fonction de libération personnalisée
    );

    gdk_cairo_set_source_pixbuf(cr, pixbuf, 0, 0);
    cairo_paint(cr);
    g_object_unref(pixbuf);

    return FALSE;
}

// 🎨 Simule un rendu d'image dans la framebuffer (test)
static void simulate_emulator_frame() {
    for (int y = 0; y < FB_HEIGHT; ++y) {
        for (int x = 0; x < FB_WIDTH; ++x) {
            int index = (y * FB_WIDTH + x) * 3;
            framebuffer[index]     = x % 256;         // R
            framebuffer[index + 1] = y % 256;         // G
            framebuffer[index + 2] = (x + y) % 256;   // B
        }
    }
    gtk_widget_queue_draw(drawing_area); // Redessine la zone
}

static void on_open_clicked(GtkWidget *widget, gpointer window) {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new("Ouvrir un fichier",
                                         GTK_WINDOW(window),
                                         GTK_FILE_CHOOSER_ACTION_OPEN,
                                         "_Annuler", GTK_RESPONSE_CANCEL,
                                         "_Ouvrir", GTK_RESPONSE_ACCEPT,
                                         NULL);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        if (selected_file) g_free(selected_file);
        selected_file = gtk_file_chooser_get_filename(chooser);
        g_print("Fichier sélectionné : %s\n", selected_file);
        if (info_label) {
            gchar *message = g_strdup_printf("Je suis une pastèque : %s", selected_file);
            gtk_label_set_text(GTK_LABEL(info_label), message);
            g_free(message);
        }
    }

    gtk_widget_destroy(dialog);
}

static void on_quit_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

GtkToolItem* create_button(const char *label_button, const char *label_icon) {
    GtkWidget *icon = gtk_image_new_from_icon_name(label_icon, GTK_ICON_SIZE_LARGE_TOOLBAR);
    return gtk_tool_button_new(icon, label_button);
}

GtkWidget* create_window(const char *label_window, int width, int height) {
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), label_window);
    gtk_window_set_default_size(GTK_WINDOW(window), width, height);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    return window;
}

GtkWidget *create_drawing_area(GtkWidget *vbox){
    GtkWidget *drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, FB_WIDTH, FB_HEIGHT);
    g_signal_connect(drawing_area, "draw", G_CALLBACK(on_draw), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), drawing_area, TRUE, TRUE, 0);

    return drawing_area;
}

void add_to_toolbar(GtkToolItem *button, GCallback function, GtkWidget *toolbar, gpointer user_data) {
    g_signal_connect(button, "clicked", function, user_data);
    gtk_toolbar_insert(GTK_TOOLBAR(toolbar), button, -1);
}