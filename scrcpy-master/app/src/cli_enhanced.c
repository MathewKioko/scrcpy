#include "cli_enhanced.h"
#include "options.h"
#include "util/log.h"

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static bool
parse_theme(const char *arg, enum sc_theme *theme) {
    if (!strcmp(arg, "default")) {
        *theme = SC_THEME_DEFAULT;
    } else if (!strcmp(arg, "dark")) {
        *theme = SC_THEME_DARK;
    } else if (!strcmp(arg, "light")) {
        *theme = SC_THEME_LIGHT;
    } else if (!strcmp(arg, "custom")) {
        *theme = SC_THEME_CUSTOM;
    } else {
        LOGE("Invalid theme: %s", arg);
        return false;
    }
    return true;
}

static bool
parse_advanced_recording_mode(const char *arg, enum sc_advanced_recording_mode *mode) {
    if (!strcmp(arg, "normal")) {
        *mode = SC_ADVANCED_RECORDING_NORMAL;
    } else if (!strcmp(arg, "split")) {
        *mode = SC_ADVANCED_RECORDING_SPLIT;
    } else if (!strcmp(arg, "scheduled")) {
        *mode = SC_ADVANCED_RECORDING_SCHEDULED;
    } else if (!strcmp(arg, "continuous")) {
        *mode = SC_ADVANCED_RECORDING_CONTINUOUS;
    } else {
        LOGE("Invalid advanced recording mode: %s", arg);
        return false;
    }
    return true;
}

bool
scrcpy_parse_enhanced_args(struct scrcpy_cli_args *args, int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        const char *arg = argv[i];
        
        if (!strcmp(arg, "--theme")) {
            if (i + 1 >= argc) {
                LOGE("--theme requires an argument");
                return false;
            }
            if (!parse_theme(argv[++i], &args->opts.enhanced_ui.theme)) {
                return false;
            }
            args->opts.enhanced_ui.show_advanced_controls = true;
        } else if (!strcmp(arg, "--enable-transparency")) {
            args->opts.enhanced_ui.enable_transparency = true;
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                char *endptr;
                float transparency = strtof(argv[++i], &endptr);
                if (*endptr != '\0' || transparency < 0.0f || transparency > 1.0f) {
                    LOGE("Invalid transparency value: %s", argv[i]);
                    return false;
                }
                args->opts.enhanced_ui.transparency_level = transparency;
            } else {
                args->opts.enhanced_ui.transparency_level = 0.8f; // Default transparency
            }
        } else if (!strcmp(arg, "--show-performance")) {
            args->opts.enhanced_ui.show_performance_overlay = true;
        } else if (!strcmp(arg, "--enable-hotkeys")) {
            args->opts.enhanced_ui.enable_hotkeys = true;
        } else if (!strcmp(arg, "--advanced-recording")) {
            if (i + 1 >= argc) {
                LOGE("--advanced-recording requires a mode argument");
                return false;
            }
            if (!parse_advanced_recording_mode(argv[++i], &args->opts.advanced_recording.mode)) {
                return false;
            }
        } else if (!strcmp(arg, "--split-duration")) {
            if (i + 1 >= argc) {
                LOGE("--split-duration requires an argument");
                return false;
            }
            char *endptr;
            uint32_t duration = strtoul(argv[++i], &endptr, 10);
            if (*endptr != '\0' || duration == 0) {
                LOGE("Invalid split duration: %s", argv[i]);
                return false;
            }
            args->opts.advanced_recording.split_duration = duration;
            args->opts.advanced_recording.mode = SC_ADVANCED_RECORDING_SPLIT;
        } else if (!strcmp(arg, "--max-storage")) {
            if (i + 1 >= argc) {
                LOGE("--max-storage requires an argument");
                return false;
            }
            char *endptr;
            uint32_t storage = strtoul(argv[++i], &endptr, 10);
            if (*endptr != '\0' || storage == 0) {
                LOGE("Invalid max storage value: %s", argv[i]);
                return false;
            }
            args->opts.advanced_recording.max_storage_gb = storage;
        } else if (!strcmp(arg, "--performance-monitoring")) {
            args->opts.enable_performance_monitoring = true;
        } else if (!strcmp(arg, "--network-optimization")) {
            args->opts.enable_network_optimization = true;
        } else if (!strcmp(arg, "--auto-update-check")) {
            args->opts.enable_auto_update_check = true;
        } else if (!strcmp(arg, "--crash-reporting")) {
            args->opts.enable_crash_reporting = true;
        } else if (!strcmp(arg, "--multi-device")) {
            args->opts.enable_multi_device_support = true;
        } else if (!strcmp(arg, "--quick-actions")) {
            args->opts.enable_quick_actions = true;
        } else if (!strcmp(arg, "--custom-shortcuts")) {
            args->opts.enable_custom_shortcuts = true;
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                args->opts.shortcut_config_file = argv[++i];
            }
        }
    }
    
    return true;
}

void
scrcpy_print_enhanced_usage(const char *program_name) {
    printf("\n");
    printf("Enhanced Features:\n");
    printf("    --theme <theme>              Set UI theme (default|dark|light|custom)\n");
    printf("    --enable-transparency[=level] Enable window transparency (0.0-1.0)\n");
    printf("    --show-performance           Show performance overlay\n");
    printf("    --enable-hotkeys             Enable enhanced hotkeys\n");
    printf("    --advanced-recording <mode>  Advanced recording mode (normal|split|scheduled|continuous)\n");
    printf("    --split-duration <seconds>   Split recording duration in seconds\n");
    printf("    --max-storage <gb>           Maximum storage for recordings in GB\n");
    printf("    --performance-monitoring     Enable performance monitoring\n");
    printf("    --network-optimization       Enable network optimization\n");
    printf("    --auto-update-check          Enable automatic update checking\n");
    printf("    --crash-reporting            Enable crash reporting\n");
    printf("    --multi-device               Enable multi-device support\n");
    printf("    --quick-actions              Enable quick actions panel\n");
    printf("    --custom-shortcuts[=file]    Enable custom shortcuts with optional config file\n");
    printf("\n");
}