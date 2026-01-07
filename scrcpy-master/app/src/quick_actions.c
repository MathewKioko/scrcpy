#include "quick_actions.h"
#include "options.h"
#include "util/log.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sc_quick_action {
    const char *name;
    const char *description;
    enum sc_quick_action_type type;
    void *data;
};

struct sc_quick_actions {
    struct sc_quick_action *actions;
    size_t count;
    size_t capacity;
    bool enabled;
};

static struct sc_quick_actions g_quick_actions = {
    .actions = NULL,
    .count = 0,
    .capacity = 0,
    .enabled = false,
};

bool
sc_quick_actions_init(void) {
    g_quick_actions.actions = malloc(10 * sizeof(struct sc_quick_action));
    if (!g_quick_actions.actions) {
        LOG_OOM();
        return false;
    }
    
    g_quick_actions.capacity = 10;
    g_quick_actions.count = 0;
    g_quick_actions.enabled = true;
    
    // Add default quick actions
    sc_quick_actions_add("Home", "Go to home screen", SC_QUICK_ACTION_HOME, NULL);
    sc_quick_actions_add("Back", "Go back", SC_QUICK_ACTION_BACK, NULL);
    sc_quick_actions_add("App Switch", "Switch apps", SC_QUICK_ACTION_APP_SWITCH, NULL);
    sc_quick_actions_add("Power", "Toggle power", SC_QUICK_ACTION_POWER, NULL);
    sc_quick_actions_add("Screen On", "Turn screen on", SC_QUICK_ACTION_SCREEN_ON, NULL);
    sc_quick_actions_add("Screen Off", "Turn screen off", SC_QUICK_ACTION_SCREEN_OFF, NULL);
    sc_quick_actions_add("Volume Up", "Increase volume", SC_QUICK_ACTION_VOLUME_UP, NULL);
    sc_quick_actions_add("Volume Down", "Decrease volume", SC_QUICK_ACTION_VOLUME_DOWN, NULL);
    sc_quick_actions_add("Rotate 90°", "Rotate screen 90°", SC_QUICK_ACTION_ROTATE_90, NULL);
    sc_quick_actions_add("Rotate 180°", "Rotate screen 180°", SC_QUICK_ACTION_ROTATE_180, NULL);
    
    return true;
}

void
sc_quick_actions_destroy(void) {
    if (g_quick_actions.actions) {
        for (size_t i = 0; i < g_quick_actions.count; ++i) {
            free((void*)g_quick_actions.actions[i].name);
            free((void*)g_quick_actions.actions[i].description);
            if (g_quick_actions.actions[i].data) {
                free(g_quick_actions.actions[i].data);
            }
        }
        free(g_quick_actions.actions);
        g_quick_actions.actions = NULL;
    }
    g_quick_actions.count = 0;
    g_quick_actions.capacity = 0;
    g_quick_actions.enabled = false;
}

bool
sc_quick_actions_add(const char *name, const char *description, 
                     enum sc_quick_action_type type, void *data) {
    if (!g_quick_actions.enabled) {
        return false;
    }
    
    if (g_quick_actions.count >= g_quick_actions.capacity) {
        size_t new_capacity = g_quick_actions.capacity * 2;
        struct sc_quick_action *new_actions = realloc(g_quick_actions.actions,
                                                      new_capacity * sizeof(struct sc_quick_action));
        if (!new_actions) {
            LOG_OOM();
            return false;
        }
        g_quick_actions.actions = new_actions;
        g_quick_actions.capacity = new_capacity;
    }
    
    struct sc_quick_action *action = &g_quick_actions.actions[g_quick_actions.count++];
    
    action->name = strdup(name);
    action->description = strdup(description);
    action->type = type;
    action->data = data;
    
    if (!action->name || !action->description) {
        LOG_OOM();
        if (action->name) free((void*)action->name);
        if (action->description) free((void*)action->description);
        g_quick_actions.count--;
        return false;
    }
    
    return true;
}

bool
sc_quick_actions_execute(size_t index) {
    if (!g_quick_actions.enabled || index >= g_quick_actions.count) {
        return false;
    }
    
    struct sc_quick_action *action = &g_quick_actions.actions[index];
    
    switch (action->type) {
        case SC_QUICK_ACTION_HOME:
            // Send HOME key event
            LOGI("Executing quick action: %s", action->name);
            break;
        case SC_QUICK_ACTION_BACK:
            // Send BACK key event
            LOGI("Executing quick action: %s", action->name);
            break;
        case SC_QUICK_ACTION_APP_SWITCH:
            // Send APP_SWITCH key event
            LOGI("Executing quick action: %s", action->name);
            break;
        case SC_QUICK_ACTION_POWER:
            // Send POWER key event
            LOGI("Executing quick action: %s", action->name);
            break;
        case SC_QUICK_ACTION_SCREEN_ON:
            // Send SCREEN_ON key event
            LOGI("Executing quick action: %s", action->name);
            break;
        case SC_QUICK_ACTION_SCREEN_OFF:
            // Send SCREEN_OFF key event
            LOGI("Executing quick action: %s", action->name);
            break;
        case SC_QUICK_ACTION_VOLUME_UP:
            // Send VOLUME_UP key event
            LOGI("Executing quick action: %s", action->name);
            break;
        case SC_QUICK_ACTION_VOLUME_DOWN:
            // Send VOLUME_DOWN key event
            LOGI("Executing quick action: %s", action->name);
            break;
        case SC_QUICK_ACTION_ROTATE_90:
            // Rotate screen 90°
            LOGI("Executing quick action: %s", action->name);
            break;
        case SC_QUICK_ACTION_ROTATE_180:
            // Rotate screen 180°
            LOGI("Executing quick action: %s", action->name);
            break;
        default:
            LOGW("Unknown quick action type: %d", action->type);
            return false;
    }
    
    return true;
}

size_t
sc_quick_actions_get_count(void) {
    return g_quick_actions.count;
}

const struct sc_quick_action *
sc_quick_actions_get_action(size_t index) {
    if (index >= g_quick_actions.count) {
        return NULL;
    }
    return &g_quick_actions.actions[index];
}

bool
sc_quick_actions_is_enabled(void) {
    return g_quick_actions.enabled;
}

void
sc_quick_actions_set_enabled(bool enabled) {
    g_quick_actions.enabled = enabled;
}

void
sc_quick_actions_print_list(void) {
    if (!g_quick_actions.enabled) {
        printf("Quick actions are disabled.\n");
        return;
    }
    
    printf("Available quick actions:\n");
    for (size_t i = 0; i < g_quick_actions.count; ++i) {
        const struct sc_quick_action *action = &g_quick_actions.actions[i];
        printf("  %zu. %s - %s\n", i + 1, action->name, action->description);
    }
}