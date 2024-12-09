project('adventofcode', 'c',
    version : '0.1',
    default_options : ['warning_level=3']
)

common_include = 'common/include'
common_src = [
    'common/src/file_utils.c'
]

executable('day1',
    include_directories: [
        common_include
    ],
    sources: [
        'day1/day1.c',
        common_src
    ]
)

executable('day2',
    include_directories: [
        common_include
    ],
    sources: [
        'day2/day2.c',
        common_src
    ]
)
