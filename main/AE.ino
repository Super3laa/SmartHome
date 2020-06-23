void toggleString(int id) {
  if (Status.substring(id - 1, id) == "1") {
    Status.setCharAt(id - 1, '0');
  } else {
    Status.setCharAt(id - 1, '1');
  }
}
void toggleSecurity(int id) {
  if (SecurityInfo.substring(id - 1, id) == "1") {
    SecurityInfo.setCharAt(id - 1, '0');
  } else {
    SecurityInfo.setCharAt(id - 1, '1');
  }
}
