#include "keyboard.h"
#include "../assembly_interface.h"
#include "../stdio.h"
#include "../types.h"

#define KBD_DATA_PORT   0x60

uint8_t read_scan_code()
{
  return inb(KBD_DATA_PORT);
}

uint8_t consume_scan_code() {
  uint8_t scan_code = read_scan_code();
  outb(0x3F8, scan_code);
  return scan_code;
}