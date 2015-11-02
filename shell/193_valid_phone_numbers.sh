#!/bin/bash
#Check valid phone number
grep -P '\(\d{3}\) \d{3}-\d{4}|\d{3}-\d{3}-\d{4}' $1
