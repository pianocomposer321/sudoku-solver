.PHONY: main
main:
	make -C bin main

.PHONY: run
run:
	make -C bin run

.PHONY: run-tests
run-tests:
	make -C bin run-tests
