CC=g++
CFLAGS=-Wall -Wextra -std=c++17
TARGET=avrg_arrays
DESTDIR=$(CURDIR)/debian/avrg-arrays
BINDIR=$(DESTDIR)/usr/bin
REQUIRED_PKGS="g++ make debhelper"

all: check_deps $(TARGET) install

$(TARGET): avrg_arrays.o
	$(CC) $(CFLAGS) -o $(TARGET) avrg_arrays.o

avrg_arrays.o: avrg_arrays.cpp
	$(CC) $(CFLAGS) -c avrg_arrays.cpp

clean:
	rm -f $(TARGET) *.o
	rm -rf $(DESTDIR)

install: $(TARGET)
	mkdir -p $(BINDIR)
	cp $(TARGET) $(BINDIR)/

check_deps:
	@missing_pkgs=""; \
	for pkg in $(REQUIRED_PKGS); do \
		dpkg -s $$pkg >/dev/null 2>&1 || missing_pkgs="$$missing_pkgs $$pkg"; \
	done; \
	if [ -n "$$missing_pkgs" ]; then \
		echo "Устанавливаются отсутствующие пакеты:$$missing_pkgs"; \
		sudo apt update && sudo apt install -y $$missing_pkgs; \
	fi
