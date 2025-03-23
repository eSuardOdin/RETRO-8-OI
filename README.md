# RETRO-8-OI
School project to create a GB emulator

# Architecture

## CPU
Modified version of Zilog Z80, runs at 4.16MhZ
8 bit processor
16 bit memory address space.

### Registers 

La Game boy a 10 registers : A, B, C, D, E, H, L, SP, PC et le Flag register F.

La particularité de ces registres est qu'on peut les utiliser unitairement comme des registres 8bits (A, B, C, D, E, H, L, (HL)) 
*(HL) est la valeur de l'adresse vers laquelle pointe HL*



| Register | Bits | Purpose                                                                                                                                                                                                              |
|----------|------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| A/AF     | 8    | Accumulator: La plupart des opérations mathématiques se font sur ce registre.  Il sert aussi de Flag register (https://gbdev.io/pandocs/CPU_Registers_and_Flags.html#the-flags-register-lower-8-bits-of-af-register) |
| B        | 8    |                                                                                                                                                                                                                      |
| C        | 8    |                                                                                                                                                                                                                      |
| D        | 8    |                                                                                                                                                                                                                      |
| E        | 8    |                                                                                                                                                                                                                      |
| H        | 8    |                                                                                                                                                                                                                      |
| L        | 8    |                                                                                                                                                                                                                      |
| SP       | 16   | Stack Pointer                                                                                                                                                                                                        |
| PC       | 16   |              

## Work RAM (WRAM)
Contient 8kB (8192b) de Work RAM

## Video RAM (VRAM)
Contient 8kB (8192b) de Video RAM

## Picture processing unit (PPU)