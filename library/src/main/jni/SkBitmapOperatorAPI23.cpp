#include <stdio.h>
#include <android/bitmap.h>
#include "SkBitmapOperatorAPI23.h"

void* SkBitmapOperatorAPI23::getNativeBitmap(JNIEnv* env, jobject javaBitmap) const {
    char* bitmap = (char*)SkBitmapOperator::getNativeBitmap(env, javaBitmap);

    if (NULL != bitmap) {
        // For Bitmap.h in Android 6:
        int offset = sizeof(void*)/*mLock*/ + sizeof(int)/*mPinnedRefCount*/;
        bitmap = *((char**)(bitmap + offset));  // Pointer to mPixelRef
        return bitmap;
    }
    return NULL;
}

