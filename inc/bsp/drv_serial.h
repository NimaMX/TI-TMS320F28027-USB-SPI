#ifndef _SERIAL_H
#define _SERIAL_H

#ifdef __cplusplus
extern "C" {
#endif

void serial_init(void);

void serial_write(char *s);

void serial_read(char *buffer);

interrupt void serial_interrupt_irq(void);

#ifdef __cplusplus
}
#endif


#endif /** _SERIAL_H */
