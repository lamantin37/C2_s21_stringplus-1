#include "s21_string.h"

#include "s21_errmsg.h"

#define ARR_SIZE(arr) (sizeof(arr) / sizeof(*arr))

int s21_sprintf(char *buf, const char *format, ...);

size_t s21_strlen(const char *str) {
  size_t counter = 0;
  for (const char *p = str; *p != '\0'; p++, counter++) {
  }
  return counter;
}

char *s21_strcpy(char *dest, const char *src) {
  char *temp_dst = dest;
  for (const char *p = src; *p != '\0'; p++) {
    *dest = *p;
    dest++;
  }
  *dest = '\0';
  return temp_dst;
}

char *s21_strncpy(char *dest, const char *src, size_t n) {
  char *temp_dst = dest;
  size_t counter = 0;
  for (const char *p = src; *p != '\0'; p++, counter++) {
    if (counter == n) {
      break;
    }
    *dest = *p;
    dest++;
  }
  if (counter < n) {
    for (; counter != n; counter++) {
      *dest = (char)0;
      dest++;
    }
  }
  return temp_dst;
}

int s21_strcmp(const char *str1, const char *str2) {
  int diff = 0;
  for (const char *p = str1;; p++) {
    diff = (int)*p - (int)*str2;
    if (*p == '\0' || *str2 == '\0') {
      break;
    }
    if (diff != 0) {
      break;
    }
    str2++;
  }
  return diff;
}

int s21_strncmp(const char *str1, const char *str2, size_t n) {
  size_t counter = 0;
  int diff = 0;
  for (const char *p = str1;; p++, counter++) {
    if (counter == n) {
      break;
    }
    diff = (int)*p - (int)*str2;
    if (*p == '\0' || *str2 == '\0') {
      break;
    }
    if (diff != 0) {
      break;
    }
    str2++;
  }
  return diff;
}

char *s21_strchr(const char *str, int c) {
  char *pointer = S21_NULL;
  for (;; str++) {
    if (*str == c) {
      pointer = (char *)str;
      break;
    }
    if (*str == '\0') {
      break;
    }
  }
  return pointer;
}

char *s21_strcat(char *dest, const char *src) {
  char *buffer_dest = dest;
  for (; *dest != '\0'; dest++) {
  }
  for (;; src++, dest++) {
    *dest = *src;
    if (*src == '\0') {
      break;
    }
  }
  return buffer_dest;
}

char *s21_strncat(char *dest, const char *src, size_t n) {
  size_t counter = 0;
  char *buffer_dest = dest;
  for (; *dest != '\0'; dest++) {
  }
  for (;; src++, dest++, counter++) {
    *dest = *src;
    if (*src == '\0') {
      break;
    }
    if (counter == n) {
      *dest = '\0';
      break;
    }
  }
  return buffer_dest;
}

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t lenght = 0;
  int flag = 0;
  for (const char *p = str1; *p != '\0'; p++) {
    for (const char *cmp = str2; *cmp != '\0'; cmp++) {
      if (*p == *cmp) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      break;
    }
    lenght++;
  }
  return lenght;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *buffer_str1 = S21_NULL;
  int flag = 0;
  for (const char *p = str1; *p != '\0'; p++) {
    for (const char *cmp = str2; *cmp != '\0'; cmp++) {
      if (*p == *cmp) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      buffer_str1 = (char *)p;
      break;
    }
  }
  return buffer_str1;
}

char *s21_strrchr(const char *str, int c) {
  char *buffer_str = S21_NULL;
  for (const char *p = str;; p++) {
    if (*p == c) {
      buffer_str = (char *)p;
    }
    if (*p == '\0') {
      break;
    }
  }
  return buffer_str;
}

size_t s21_strspn(const char *str1, const char *str2) {
  size_t lenght = 0;
  int flag = 0;
  for (const char *p = str1; *p != '\0'; p++) {
    flag = 0;
    for (const char *cmp = str2; *cmp != '\0'; cmp++) {
      if (*p == *cmp) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      break;
    }
    lenght++;
  }
  return lenght;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *ch = S21_NULL;
  char *buffer_needle = (char *)needle;
  for (const char *p = haystack;; p++) {
    if (*p == *buffer_needle) {
      buffer_needle++;
    } else {
      buffer_needle = (char *)needle;
    }
    if (*buffer_needle == '\0') {
      if (p == haystack) {
        ch = (char *)p;
      } else {
        ch = (char *)p - (s21_strlen(needle) - 1);
      }
      break;
    }
    if (*p == '\0') {
      break;
    }
  }
  return ch;
}

void *s21_memchr(const void *str, int c, size_t n) {
  char *ch = S21_NULL;
  for (; n > 0; n--) {
    if (*(char *)str == c) {
      ch = (char *)str;
      break;
    }
    str++;
  }
  return ch;
}

int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int diff = 0;
  for (; n > 0; n--) {
    diff = *(char *)str1 - *(char *)str2;
    if (diff != 0) {
      break;
    }
    str2++, str1++;
  }
  return diff;
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
  char *buffer_dest = dest;
  size_t counter = 0;
  for (const char *p = src; counter != n; p++, counter++) {
    *((char *)dest) = *p;
    dest++;
  }
  return buffer_dest;
}

void *s21_memmove(void *dst, const void *src, size_t len) {
  char *d = dst;
  const char *s = src;
  if (dst < src) {
    for (size_t i = 0; i < len; ++i) {
      *d++ = *s++;
    }
  } else if (dst > src) {
    d += len - 1;
    s += len - 1;
    for (size_t i = 0; i < len; ++i) {
      *d-- = *s--;
    }
  }
  return dst;
}

void *s21_memset(void *str, int c, size_t n) {
  char *buffer_str = str;
  for (size_t i = 0; i < n; i++) {
    *((char *)str) = (char)c;
    str++;
  }
  return buffer_str;
}

char *s21_strerror(int errnum) {
  char *p = NULL;
  if (errnum < (int)ARR_SIZE(s21_str_errlist)) {
    p = (char *)s21_str_errlist[errnum];
  } else {
    static char uknown_error[100] = {0};
    s21_sprintf(uknown_error, "%s %d", uknown_error_msg, errnum);
    p = uknown_error;
  }
  return p;
}

char *s21_strtok(char *str, const char *delim) {
  static char *pointer = S21_NULL;
  if (str) pointer = str;
  char *p = S21_NULL;
  if (pointer && *pointer) {
    size_t skip_len = s21_strspn(pointer, delim);
    p = pointer + skip_len;
    if (*p) {
      pointer = s21_strpbrk(p, delim);
      if (pointer && *pointer) {
        *pointer = '\0';
        ++pointer;
      }
    } else {
      p = S21_NULL;
    }
  }
  return p;
}

void *s21_to_upper(const char *str) {
  char *new_str = S21_NULL;
  if (str) new_str = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
  if (new_str) {
    s21_strcpy(new_str, str);
    for (char *p = new_str; *p != '\0'; p++) {
      if (*p >= 'a' && *p <= 'z') {
        *p -= 32;
      }
    }
  }
  return (void *)new_str;
}

void *s21_to_lower(const char *str) {
  char *new_str = S21_NULL;
  if (str) new_str = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
  if (new_str) {
    s21_strcpy(new_str, str);
    for (char *p = new_str; *p != '\0'; p++) {
      if (*p >= 'A' && *p <= 'Z') {
        *p += 32;
      }
    }
  }
  return (void *)new_str;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *first_part = S21_NULL;
  short error_flag = 0;
  if (src && str && start_index <= s21_strlen(src)) {
    first_part = malloc((s21_strlen(str) + s21_strlen(src) + 8));
    s21_memset(first_part, 0, sizeof(first_part));
    s21_strncat(first_part, src, start_index);
    s21_strcat(first_part, str);
    char *second_part = malloc((s21_strlen(src) - start_index + 1));
    for (size_t j = start_index, i = 0; i < s21_strlen(src) - start_index + 1;
         j++, i++)
      second_part[i] = src[j];
    s21_strcat(first_part, second_part);
    free(second_part);
  } else {
    error_flag = 1;
  }
  return error_flag ? S21_NULL : (void *)first_part;
}

void *s21_trim(const char *src, const char *trim_chars) {
  int error_flag = 0;
  char *new_str = S21_NULL;
  char default_trim[4] = " \n\t";
  if (src[0] != '\0') {
    if (trim_chars == S21_NULL || s21_strlen(trim_chars) == 0) {
      trim_chars = default_trim;
    }
    new_str = (char *)calloc(s21_strlen(src) + 1, sizeof(char));
    if (new_str == S21_NULL) {
      error_flag = 1;
    } else {
      size_t pos_left = 0, pos_right = 0;
      for (size_t i = 0; i <= s21_strlen(src); i++) {
        size_t counter = 0;
        for (size_t j = 0; j < s21_strlen(trim_chars); j++) {
          if (src[i] == trim_chars[j]) {
            pos_left++;
            continue;
          } else {
            counter++;
          }
        }
        if (counter >= s21_strlen(trim_chars)) break;
      }
      for (size_t i = s21_strlen(src) - 1; i >= (s21_strlen(src) / 2); i--) {
        size_t counter = 0;
        for (size_t j = 0; j < s21_strlen(trim_chars); j++) {
          if (src[i] == trim_chars[j]) {
            pos_right++;
            continue;
          } else {
            counter++;
          }
        }
        if (counter >= s21_strlen(trim_chars)) break;
      }
      for (size_t i = pos_left, j = 0; i < s21_strlen(src) - pos_right;
           i++, j++)
        new_str[j] = src[i];
    }
  } else {
    error_flag = 1;
  }
  return error_flag ? S21_NULL : (void *)new_str;
}
