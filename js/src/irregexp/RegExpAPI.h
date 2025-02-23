/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This Source Code Form is "Incompatible With Secondary Licenses", as
 * defined by the Mozilla Public License, v. 2.0.
 */

/* This is the interface that the regexp engine exposes to SpiderMonkey. */

#ifndef regexp_RegExpAPI_h
#define regexp_RegExpAPI_h

#include "mozilla/MemoryReporting.h"

#include "frontend/TokenStream.h"
#include "jscntxt.h"
#include "vm/RegExpObject.h"

namespace js {
namespace irregexp {

Isolate* CreateIsolate(JSContext* cx);
void DestroyIsolate(Isolate* isolate);

size_t IsolateSizeOfIncludingThis(Isolate* isolate,
                                  mozilla::MallocSizeOf mallocSizeOf);

bool CheckPatternSyntax(JSContext* cx, frontend::TokenStreamAnyChars& ts,
                        const mozilla::Range<const char16_t> chars,
                        JS::RegExpFlags flags);
bool CheckPatternSyntax(JSContext* cx, frontend::TokenStreamAnyChars& ts,
                        HandleAtom pattern, JS::RegExpFlags flags);
bool CompilePattern(JSContext* cx, MutableHandleRegExpShared re,
                    HandleLinearString input, RegExpShared::CodeKind codeKind);

RegExpRunStatus Execute(JSContext* cx, MutableHandleRegExpShared re,
                        HandleLinearString input, size_t start,
                        MatchPairs* matches);

}  // namespace irregexp
}  // namespace js

#endif /* regexp_RegExpAPI_h */
