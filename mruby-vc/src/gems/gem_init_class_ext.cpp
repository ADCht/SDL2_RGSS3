/*
 * This file is loading the irep
 * Ruby GEM code.
 *
 * IMPORTANT:
 *   This file was generated!
 *   All manual changes will get lost.
 */
#include <stdlib.h>
#include <mruby.h>
#include <mruby/irep.h>
/* dumped in little endian order.
   use `mrbc -E` option for big endian CPU. */
#include <stdint.h>
#ifdef __cplusplus
extern const uint8_t gem_mrblib_irep_mruby_class_ext[];
#endif
const uint8_t
#if defined __GNUC__
__attribute__((aligned(4)))
#elif defined _MSC_VER
__declspec(align(4))
#endif
gem_mrblib_irep_mruby_class_ext[] = {
0x45,0x54,0x49,0x52,0x30,0x30,0x30,0x36,0x3e,0xa5,0x00,0x00,0x03,0x3a,0x4d,0x41,
0x54,0x5a,0x30,0x30,0x30,0x30,0x49,0x52,0x45,0x50,0x00,0x00,0x02,0xd5,0x30,0x30,
0x30,0x32,0x00,0x00,0x00,0x57,0x00,0x01,0x00,0x03,0x00,0x01,0x00,0x00,0x00,0x0d,
0x0f,0x01,0x0f,0x02,0x5a,0x01,0x00,0x5c,0x01,0x00,0x37,0x01,0x67,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x01,0x00,0x06,0x4d,0x6f,0x64,0x75,0x6c,0x65,0x00,0x00,0x00,
0x00,0xe6,0x00,0x01,0x00,0x03,0x00,0x05,0x00,0x00,0x00,0x2d,0x61,0x01,0x56,0x02,
0x00,0x5d,0x01,0x00,0x61,0x01,0x56,0x02,0x01,0x5d,0x01,0x01,0x61,0x01,0x56,0x02,
0x02,0x5d,0x01,0x02,0x61,0x01,0x56,0x02,0x03,0x5d,0x01,0x03,0x61,0x01,0x56,0x02,
0x04,0x5d,0x01,0x04,0x0e,0x01,0x04,0x37,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x05,0x00,0x01,0x3c,0x00,0x00,0x02,0x3c,0x3d,0x00,0x00,0x01,0x3e,0x00,0x00,0x02,
0x3e,0x3d,0x00,0x00,0x03,0x3c,0x3d,0x3e,0x00,0x00,0x00,0x00,0x9f,0x00,0x03,0x00,
0x06,0x00,0x00,0x00,0x00,0x00,0x1f,0x00,0x33,0x04,0x00,0x00,0x10,0x03,0x01,0x04,
0x01,0x2e,0x03,0x00,0x01,0x23,0x03,0x00,0x16,0x12,0x03,0x21,0x00,0x1d,0x10,0x03,
0x01,0x04,0x01,0x43,0x03,0x37,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,
0x06,0x65,0x71,0x75,0x61,0x6c,0x3f,0x00,0x00,0x00,0x01,0xbf,0x00,0x03,0x00,0x07,
0x00,0x00,0x00,0x00,0x00,0x52,0x00,0x00,0x33,0x04,0x00,0x00,0x01,0x03,0x01,0x1b,
0x04,0x00,0x2e,0x03,0x01,0x01,0x22,0x03,0x00,0x1e,0x10,0x03,0x1b,0x04,0x02,0x4f,
0x05,0x00,0x2e,0x03,0x03,0x02,0x10,0x03,0x2e,0x03,0x04,0x00,0x01,0x04,0x01,0x2e,
0x03,0x05,0x01,0x23,0x03,0x00,0x36,0x11,0x03,0x37,0x03,0x21,0x00,0x50,0x01,0x03,
0x01,0x2e,0x03,0x04,0x00,0x10,0x04,0x2e,0x03,0x05,0x01,0x23,0x03,0x00,0x4e,0x12,
0x03,0x37,0x03,0x21,0x00,0x50,0x0f,0x03,0x37,0x03,0x00,0x00,0x00,0x01,0x00,0x00,
0x1e,0x63,0x6f,0x6d,0x70,0x61,0x72,0x65,0x64,0x20,0x77,0x69,0x74,0x68,0x20,0x6e,
0x6f,0x6e,0x20,0x63,0x6c,0x61,0x73,0x73,0x2f,0x6d,0x6f,0x64,0x75,0x6c,0x65,0x00,
0x00,0x00,0x06,0x00,0x06,0x4d,0x6f,0x64,0x75,0x6c,0x65,0x00,0x00,0x05,0x69,0x73,
0x5f,0x61,0x3f,0x00,0x00,0x09,0x54,0x79,0x70,0x65,0x45,0x72,0x72,0x6f,0x72,0x00,
0x00,0x05,0x72,0x61,0x69,0x73,0x65,0x00,0x00,0x09,0x61,0x6e,0x63,0x65,0x73,0x74,
0x6f,0x72,0x73,0x00,0x00,0x08,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,0x3f,0x00,0x00,
0x00,0x00,0x9f,0x00,0x03,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x1f,0x00,0x00,0x00,
0x33,0x04,0x00,0x00,0x10,0x03,0x01,0x04,0x01,0x2e,0x03,0x00,0x01,0x23,0x03,0x00,
0x16,0x12,0x03,0x21,0x00,0x1d,0x10,0x03,0x01,0x04,0x01,0x45,0x03,0x37,0x03,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x06,0x65,0x71,0x75,0x61,0x6c,0x3f,0x00,
0x00,0x00,0x00,0xfc,0x00,0x03,0x00,0x07,0x00,0x00,0x00,0x00,0x00,0x27,0x00,0x00,
0x33,0x04,0x00,0x00,0x01,0x03,0x01,0x1b,0x04,0x00,0x2e,0x03,0x01,0x01,0x22,0x03,
0x00,0x1e,0x10,0x03,0x1b,0x04,0x02,0x4f,0x05,0x00,0x2e,0x03,0x03,0x02,0x01,0x03,
0x01,0x10,0x04,0x42,0x03,0x37,0x03,0x00,0x00,0x00,0x01,0x00,0x00,0x1e,0x63,0x6f,
0x6d,0x70,0x61,0x72,0x65,0x64,0x20,0x77,0x69,0x74,0x68,0x20,0x6e,0x6f,0x6e,0x20,
0x63,0x6c,0x61,0x73,0x73,0x2f,0x6d,0x6f,0x64,0x75,0x6c,0x65,0x00,0x00,0x00,0x04,
0x00,0x06,0x4d,0x6f,0x64,0x75,0x6c,0x65,0x00,0x00,0x05,0x69,0x73,0x5f,0x61,0x3f,
0x00,0x00,0x09,0x54,0x79,0x70,0x65,0x45,0x72,0x72,0x6f,0x72,0x00,0x00,0x05,0x72,
0x61,0x69,0x73,0x65,0x00,0x00,0x00,0x01,0x48,0x00,0x04,0x00,0x07,0x00,0x00,0x00,
0x00,0x00,0x45,0x00,0x33,0x04,0x00,0x00,0x10,0x04,0x01,0x05,0x01,0x2e,0x04,0x00,
0x01,0x23,0x04,0x00,0x15,0x06,0x04,0x37,0x04,0x01,0x04,0x01,0x1b,0x05,0x01,0x2e,
0x04,0x02,0x01,0x22,0x04,0x00,0x27,0x0f,0x04,0x37,0x04,0x10,0x04,0x01,0x05,0x01,
0x42,0x04,0x01,0x03,0x04,0x23,0x04,0x00,0x39,0x05,0x04,0x37,0x04,0x24,0x03,0x00,
0x41,0x07,0x04,0x37,0x04,0x0f,0x04,0x37,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x03,0x00,0x06,0x65,0x71,0x75,0x61,0x6c,0x3f,0x00,0x00,0x06,0x4d,0x6f,0x64,0x75,
0x6c,0x65,0x00,0x00,0x05,0x69,0x73,0x5f,0x61,0x3f,0x00,0x4c,0x56,0x41,0x52,0x00,
0x00,0x00,0x47,0x00,0x00,0x00,0x03,0x00,0x05,0x6f,0x74,0x68,0x65,0x72,0x00,0x01,
0x26,0x00,0x03,0x63,0x6d,0x70,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x02,0x00,0x00,
0x00,0x01,0x00,0x01,0x00,0x02,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x02,0x00,0x00,
0x00,0x01,0x00,0x01,0x00,0x02,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x02,0x00,0x02,
0x00,0x03,0x45,0x4e,0x44,0x00,0x00,0x00,0x00,0x08,
};
void mrb_mruby_class_ext_gem_init(mrb_state *mrb);
void mrb_mruby_class_ext_gem_final(mrb_state *mrb);

void GENERATED_TMP_mrb_mruby_class_ext_gem_init(mrb_state *mrb) {
  int ai = mrb_gc_arena_save(mrb);
  mrb_mruby_class_ext_gem_init(mrb);
  mrb_load_irep(mrb, gem_mrblib_irep_mruby_class_ext);
  if (mrb->exc) {
    mrb_print_error(mrb);
    mrb_close(mrb);
    exit(EXIT_FAILURE);
  }
  mrb_gc_arena_restore(mrb, ai);
}

void GENERATED_TMP_mrb_mruby_class_ext_gem_final(mrb_state *mrb) {
  mrb_mruby_class_ext_gem_final(mrb);
}
