hexadecimal_convertor
=====================

usage:

	hexReadWrite <option> <str>

	Options:
	  <-w  | --write>   Convert a string to hexa pairs
	  <-r  | --read>    Convert hexa pairs to a string
	  <-i  | --readi>   Convert hexa pairs to a string of integers


Examples:

	./hexReadWrite -w "test"
	  74657374


	./hexReadWrite -r "74657374"
	  test
	./hexReadWrite -r "74 65 73 74"
	  test

	./hexReadWrite -i "74657374"
	  116 101 115 116
	./hexReadWrite -i "74 65 73 74"
	  116 101 115 116

