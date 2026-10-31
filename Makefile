# Nombre del archivo ejecutable final
TARGET = organizador_hotelero

# Compilador de C++ y flags de optimización/advertencias
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Detectar automáticamente todos los archivos .cpp en la carpeta actual
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Regla principal por defecto
all: $(TARGET)

# Regla para enlazar el ejecutable a partir de los archivos objeto
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla genérica para compilar archivos fuente a archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos temporales y el ejecutable
clean:
	rm -f $(OBJS) $(TARGET)

# Indicar que estas reglas no corresponden a archivos físicos
.PHONY: all clean
