#include <fcntl.h>
#include <stdio.h>
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
  return 0;
}
