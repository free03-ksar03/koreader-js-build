#include "../include/js_bridge.h"
#include "../quickjs/quickjs.h"
#include <string.h>
#include <stdlib.h>

static JSRuntime *runtime = NULL;
static JSContext *context = NULL;
static char *last_result = NULL;

static void set_last_result(const char *str)
{
    if (last_result) {
        free(last_result);
        last_result = NULL;
    }
    if (str) {
        last_result = strdup(str);
    }
}

int koreader_js_init(void)
{
    runtime = JS_NewRuntime();
    if (!runtime)
        return 0;

    context = JS_NewContext(runtime);
    if (!context) {
        JS_FreeRuntime(runtime);
        runtime = NULL;
        return 0;
    }

    return 1;
}

void koreader_js_shutdown(void)
{
    set_last_result(NULL);

    if (context) {
        JS_FreeContext(context);
        context = NULL;
    }

    if (runtime) {
        JS_FreeRuntime(runtime);
        runtime = NULL;
    }
}

int koreader_js_eval(const char *code)
{
    if (!context || !code)
        return -1;

    JSValue result = JS_Eval(context, code, strlen(code), "<koreader-js>", JS_EVAL_TYPE_GLOBAL);

    if (JS_IsException(result)) {
        JSValue exception = JS_GetException(context);
        const char *err_str = JS_ToCString(context, exception);
        set_last_result(err_str ? err_str : "unknown error");
        if (err_str)
            JS_FreeCString(context, err_str);
        JS_FreeValue(context, exception);
        JS_FreeValue(context, result);
        return -1;
    }

    const char *str = JS_ToCString(context, result);
    set_last_result(str ? str : "");
    if (str)
        JS_FreeCString(context, str);

    JS_FreeValue(context, result);
    return 0;
}

const char *koreader_js_last_result(void)
{
    return last_result ? last_result : "";
}

const char *koreader_js_version(void)
{
    return "KOReader JavaScript Bridge 0.4";
}
