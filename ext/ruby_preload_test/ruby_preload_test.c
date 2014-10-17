#include "ruby_preload_test.h"
#include <dlfcn.h>
#include <stdio.h>

VALUE rb_mRubyPreloadTest;

static VALUE *(*rb_f_puts_orig)(int argc, VALUE *argv, VALUE recv) = 0;

static VALUE
rb_f_puts(int argc, VALUE *argv, VALUE recv)
{
  printf("preloaded\n");
  printf("%d", 111);
  VALUE *v = (*rb_f_puts_orig)(argc, argv, recv);
  if (recv == rb_stdout) {
    return rb_io_puts(argc, argv, recv);
  }
  return rb_funcall2(rb_stdout, rb_intern("puts"), argc, argv);
}

void
Init_ruby_preload_test(void)
{
  printf("%d", 111);
  rb_f_puts_orig = (void *(*)(size_t))dlsym(RTLD_NEXT, "rb_f_puts");

  rb_mRubyPreloadTest = rb_define_module("RubyPreloadTest");
}
