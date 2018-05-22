test: FORCE
	# Run all tests.
	g++ -std=c++17 -pedantic -Wall -Wextra -Wno-missing-braces -DTEST -lcppunit a*.cc test/*.cc
	./a.out

*.cc: FORCE
	# Compile $@.
	g++ -std=c++17 -pedantic -Wall -Wextra -Wno-missing-braces $@
	./a.out

main:
	for f in a*.cc; do make "$$f"; done


cppunit:
	# Install CppUnit.
	if uname | grep -q Darwin; then brew install cppunit; fi
	if [ -e /etc/debian_version ]; then apt-get update && apt-get install libcppunit-dev; fi

count:
	# Compare the number of tests defined and the number of tests enabled.
	grep -r "::test_" test/*.cc | wc -l
	grep -r "TEST(test_" test/*.cc | wc -l
	[ $$(grep -r "::test_" test/*.cc | wc -l) -eq $$(grep -r "TEST(test_" test/*.cc | wc -l) ]

FORCE:
