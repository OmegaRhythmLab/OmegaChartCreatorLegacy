{
	"targets" : [
		{
			"target_name": "occ-kernal",
			"sources": [ "src/main.cpp" ]
		}
		'conditions': [
			['OS=="mac"', {
				'cflags+': ['-fvisibility=hidden'],
				'xcode_settings': {
					'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES', # -fvisibility=hidden
				}
			}],
		]
	]
	}
