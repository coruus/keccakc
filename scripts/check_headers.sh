find keccak -name "*.h" | parallel "echo {} ; tail -1 {}"
