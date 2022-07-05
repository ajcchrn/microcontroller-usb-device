UCLIBCXX_VERSION = 0.2.5
UCLIBCXX_DIR = uClibc++-$(UCLIBCXX_VERSION) 
UCLIBCXX_URL = https://git.busybox.net/uClibc++/snapshot/
UCLIBCXX_TARBALL = uClibc++-$(UCLIBCXX_VERSION).tar.bz2

uClibc++: $(UCLIBCXX_DIR)
	
$(UCLIBCXX_DIR): $(UCLIBCXX_TARBALL)
	tar -xf $^

$(UCLIBCXX_TARBALL):
	curl -o $@ $(UCLIBCXX_URL)/$(UCLIBCXX_TARBALL) 

.PHONY: clean
clean:
	-rm -rf $(UCLIBCXX_DIR) $(UCLIBCXX_TARBALL)
