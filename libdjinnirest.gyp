{
    "targets": [
        {
          'target_name': 'libdjinnirest',
          'type': 'static_library',
          'conditions': [],
          'dependencies': [
            'deps/json11.gyp:json11',
          ],
          'sources': [
            # just automatically include all cpp and hpp files in src/ (for now)
            # '<!' is shell expand
            # '@' is to splat the arguments into list items
            "<!@(python deps/djinni/example/glob.py src/ *.cpp *.hpp)",
          ],
          'include_dirs': [
          ],
          'all_dependent_settings': {
            'include_dirs': [
              'deps',
            ],
          },
        },
        {
            "target_name": "libdjinnirest_jni",
            "type": "shared_library",
            "dependencies": [
              "./deps/djinni/support-lib/support_lib.gyp:djinni_jni",
              "libdjinnirest"
            ],
            "ldflags": [ "-llog", "-Wl,--build-id,--gc-sections,--exclude-libs,ALL" ],
            "sources": [
              "./deps/djinni/support-lib/jni/djinni_main.cpp",
              "<!@(python deps/djinni/example/glob.py generated-src/jni   '*.cpp')",
              "<!@(python deps/djinni/example/glob.py generated-src/cpp   '*.cpp')",
              "<!@(python deps/djinni/example/glob.py src '*.cpp')",
            ],
            "include_dirs": [
              "generated-src/jni",
              "generated-src/cpp",
              "src",
            ],
        },
        {
            "target_name": "libdjinnirest_objc",
            "type": 'static_library',
            "dependencies": [
              "./deps/djinni/support-lib/support_lib.gyp:djinni_objc",
              "libdjinnirest"
            ],
            'direct_dependent_settings': {

            },
            "sources": [
              "<!@(python deps/djinni/example/glob.py generated-src/objc  '*.cpp' '*.h' '*.mm' '*.m')",
              "<!@(python deps/djinni/example/glob.py generated-src/cpp   '*.cpp' '*.hpp')",
              "<!@(python deps/djinni/example/glob.py src '*.cpp' '*.hpp')",
            ],
            "include_dirs": [
              "generated-src/objc",
              "generated-src/cpp",
              "src",
              "deps",
            ],
            'all_dependent_settings': {
              'include_dirs': [
                'deps',
              ],
            },
        },
    ],
}
