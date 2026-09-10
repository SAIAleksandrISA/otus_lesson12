BIN_DIR = bin

all: $(BIN_DIR)/mapper $(BIN_DIR)/reducer_mean $(BIN_DIR)/reducer_variance

$(BIN_DIR)/mapper: mapper.cpp | $(BIN_DIR)
	g++ -o $@ mapper.cpp

$(BIN_DIR)/reducer_mean: reducer_mean.cpp | $(BIN_DIR)
	g++ -o $@ reducer_mean.cpp

$(BIN_DIR)/reducer_variance: reducer_variance.cpp | $(BIN_DIR)
	g++ -o $@ reducer_variance.cpp

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)