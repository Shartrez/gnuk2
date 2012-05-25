typedef void (*handler)(void);
extern handler vector[12];

static inline const uint8_t *
unique_device_id (void)
{
  const uint8_t * (*func) (void) = (const uint8_t * (*)(void))vector[0];

  return (*func) ();
}

static inline void
set_led (int on)
{
  void (*func) (int) = (void (*)(int))vector[1];

  return (*func) (on);
}

static inline void
flash_unlock (void)
{
  (*vector[2]) ();
}

static inline int
flash_program_halfword (uint32_t addr, uint16_t data)
{
  int (*func) (uint32_t, uint16_t) = (int (*)(uint32_t, uint16_t))vector[3];

  return (*func) (addr, data);
}

static inline int
flash_erase_page (uint32_t addr)
{
  int (*func) (uint32_t) = (int (*)(uint32_t))vector[4];

  return (*func) (addr);
}

static inline int
flash_check_blank (const uint8_t *p_start, size_t size)
{
  int (*func) (const uint8_t *, int) = (int (*)(const uint8_t *, int))vector[5];

  return (*func) (p_start, size);
}

static inline int
flash_write (uint32_t dst_addr, const uint8_t *src, size_t len)
{
  int (*func) (uint32_t, const uint8_t *, size_t)
    = (int (*)(uint32_t, const uint8_t *, size_t))vector[6];

  return (*func) (dst_addr, src, len);
}

static inline int
flash_protect (void)
{
  int (*func) (void) = (int (*)(void))vector[7];

  return (*func) ();
}

static inline void __attribute__((noreturn))
flash_mass_erase_and_exec (void)
{
  void (*func) (void) = (void (*)(void))vector[8];

  (*func) ();
  for (;;);
}

static inline void
usb_lld_sys_init (void)
{
  (*vector[9]) ();
}

static inline void
usb_lld_sys_shutdown (void)
{
  (*vector[10]) ();
}

static inline void
nvic_system_reset (void)
{
  (*vector[11]) ();
}