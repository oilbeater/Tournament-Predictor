#! /bin/sh
./basic_predictor < gcc.log
./basic_predictor < compress.log
./basic_predictor < crafty.log
./basic_predictor < gzip.log
./basic_predictor < mcf.log
./basic_predictor < parser.log
./basic_predictor < vpr.log
./tournament < gcc.log
./tournament < compress.log
./tournament < crafty.log
./tournament < gzip.log
./tournament < mcf.log
./tournament < parser.log
./tournament < vpr.log
