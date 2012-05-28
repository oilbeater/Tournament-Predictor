predictor: basic_predictor.cc tournament.cc
			g++ basic_predictor.cc -o basic_predictor
			g++ tournament.cc -o tournament
clean:
			rm basic_predictor tournament
