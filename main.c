#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int fd = open("input.txt", O_RDONLY);
  if (fd < 0) {
    return 1;
  }
  struct stat sb;
  if (fstat(fd, &sb) < 0) {
    close(fd);
    return 1;
  }
  printf("File size: %lld bytes\n", (long long)sb.st_size);
  char *data = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (data == MAP_FAILED) {
    close(fd);
    return 1;
  }
  for (off_t i = 0; i < sb.st_size; i++) {
    putchar(data[i]);
  }
  munmap(data, sb.st_size);
  close(fd);
  return 0;
}
