TEMPLATE = subdirs

SUBDIRS += src tests

CONFIG += ordered

check.target = check
check.commands = (cd tests && ./tests)
check.depends = sub-tests
QMAKE_EXTRA_TARGETS += check
