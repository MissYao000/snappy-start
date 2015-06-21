// Copyright 2015 Google Inc. All Rights Reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <signal.h>


static int my_errno;

#define SYS_ERRNO my_errno
#include "linux_syscall_support.h"


void _start() {
  sys_kill(sys_getpid(), SIGUSR1);

  static const char string[] = "In example_prog.c!\n";
  sys_write(1, string, sizeof(string) - 1);
  sys_exit_group(0);
}
