#!/usr/bin/env perl
print+((Fizz)[$_%3].(Buzz)[$_%5]||$_)."\n" for 1..100
