#ifndef SCRCPY_CLI_ENHANCED_H
#define SCRCPY_CLI_ENHANCED_H

#include "common.h"
#include "cli.h"

bool
scrcpy_parse_enhanced_args(struct scrcpy_cli_args *args, int argc, char *argv[]);

void
scrcpy_print_enhanced_usage(const char *program_name);

#endif