# Use a clean image that contains standard C++ compilers
FROM ubuntu:22.04

# Install essential compilation dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    libasio-dev \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Download the Crow Web Framework header directly
RUN git clone https://github.com/CrowCpp/Crow.git && \
    cp -r Crow/include/* .

# Copy your source code into the machine build layer
COPY main.cpp .

# Compile your code with optimization flags
RUN g++ -O3 -std=c++17 main.cpp -I. -lpthread -o chatbot_server

# Tell Render to launch your compiled engine binary
CMD ["./chatbot_server"]