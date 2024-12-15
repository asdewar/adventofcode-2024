project('adventofcode', 'c',
    version : '0.1',
    default_options : [
        'buildtype=debug',
        'werror=false',
        'warning_level=3',
        'optimization=2'
    ]
)

common_include = 'common/include'
common_src = [
    'common/src/file_utils.c',
    'common/src/pattern_searcher.c',
    'common/src/matrix.c',
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

executable('day3',
    include_directories: [
        common_include
    ],
    sources: [
        'day3/day3.c',
        common_src
    ]
)

executable('day4',
    include_directories: [
        common_include
    ],
    sources: [
        'day4/day4.c',
        common_src
    ]
)
