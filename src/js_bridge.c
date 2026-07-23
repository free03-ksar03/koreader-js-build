#include "../include/js_bridge.h"
#include "../quickjs/quickjs.h"

static JSRuntime *runtime = NULL;
static JSContext *context = NULL;

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
    (void)code;
    return -1;
}

const char *koreader_js_version(void)
{
    return "KOReader JavaScript Bridge 0.2";
}
