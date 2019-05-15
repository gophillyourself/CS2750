#!/bin/bash

echo "just parens"
var="Hello"
echo $var
(var="Hi"; echo $var); echo $var

echo 
echo "with export"
var="hi"
export var
echo $var
(echo $var; var="Hello"; echo $var); echo $var

echo
echo "curly braces"
var="Hi"
export var
echo $var
{ echo $var; var="Hello"; echo $var;}; echo $var
