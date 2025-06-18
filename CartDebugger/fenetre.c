#include <gtk/gtk.h>

#define FB_WIDTH  940
#define FB_HEIGHT 830

static gchar *selected_file = NULL;
static guint8 framebuffer[FB_WIDTH * FB_HEIGHT * 3]; // Simulé: RGB888
static GtkWidget *drawing_area;
static GtkWidget *info_label;

#include "ui.c"

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *toolbar;
    GtkToolItem *open_button, *quit_button;
    GtkWidget *icon_open, *icon_quit;

    gtk_init(&argc, &argv);

    window = create_window("Cartrigde Debugger", 940, 830);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

    open_button = create_button("Ouvrir", "folder-open");

    add_to_toolbar(open_button, G_CALLBACK(on_open_clicked), toolbar, window);

    quit_button = create_button("Quitter", "application-exit");

    add_to_toolbar(quit_button, G_CALLBACK(on_quit_clicked), toolbar, window);

    gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 0);

    info_label = gtk_label_new("Cartridge informations :");
    gtk_label_set_xalign(GTK_LABEL(info_label), 0.0); // Aligné à gauche
    gtk_box_pack_start(GTK_BOX(vbox), info_label, FALSE, FALSE, 5);
    gtk_widget_set_margin_bottom(info_label, 20);


    // 🎨 Zone de dessin de la framebuffer
    drawing_area = create_drawing_area(vbox);

    gtk_widget_show_all(window);

    // ⏱️ Simule une première frame
    simulate_emulator_frame();

    gtk_main();

    if (selected_file) g_free(selected_file);
    return 0;
}
