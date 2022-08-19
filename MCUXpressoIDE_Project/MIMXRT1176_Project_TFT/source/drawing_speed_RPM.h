#ifndef DRAWING_SPEED_RPM_H
#define DRAWING_SPEED_RPM_H

void convert_number_to_Text(uint16_t speed_val_local, char *text_ptr);
void drawing_speed_rpm_update(void);
void drawing_speed_update(void);
void drawing_rpm_update(void);

extern uint8_t drawing_speed_val ;// = 0;
extern uint8_t drawing_speed_dir;

extern uint8_t drawing_rpm_val; // = 0;
extern uint8_t drawing_rpm_dir;

#endif /*DRAWING_SPEED_RPM_H*/
