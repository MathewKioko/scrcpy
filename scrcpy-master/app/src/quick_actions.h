#ifndef SCRCPY_QUICK_ACTIONS_H
#define SCRCPY_QUICK_ACTIONS_H

#include "common.h"

enum sc_quick_action_type {
    SC_QUICK_ACTION_HOME,
    SC_QUICK_ACTION_BACK,
    SC_QUICK_ACTION_APP_SWITCH,
    SC_QUICK_ACTION_POWER,
    SC_QUICK_ACTION_SCREEN_ON,
    SC_QUICK_ACTION_SCREEN_OFF,
    SC_QUICK_ACTION_VOLUME_UP,
    SC_QUICK_ACTION_VOLUME_DOWN,
    SC_QUICK_ACTION_ROTATE_90,
    SC_QUICK_ACTION_ROTATE_180,
    SC_QUICK_ACTION_ROTATE_270,
    SC_QUICK_ACTION_RECORD_START,
    SC_QUICK_ACTION_RECORD_STOP,
    SC_QUICK_ACTION_CUSTOM,
};

struct sc_quick_action {
    const char *name;
    const char *description;
    enum sc_quick_action_type type;
    void *data;
};

bool
sc_quick_actions_init(void);

void
sc_quick_actions_destroy(void);

bool
sc_quick_actions_add(const char *name, const char *description, 
                     enum sc_quick_action_type type, void *data);

bool
sc_quick_actions_execute(size_t index);

size_t
sc_quick_actions_get_count(void);

const struct sc_quick_action *
sc_quick_actions_get_action(size_t index);

bool
sc_quick_actions_is_enabled(void);

void
sc_quick_actions_set_enabled(bool enabled);

void
sc_quick_actions_print_list(void);

#endif