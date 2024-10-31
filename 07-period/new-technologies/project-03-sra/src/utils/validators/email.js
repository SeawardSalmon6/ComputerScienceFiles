const EMAIL_REGEX =
  /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|.(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;

export function emailValidator(value, users = [], { unique = false } = {}) {
  console.log(value);

  if (!value) {
    return false;
  }

  return (
    String(email).toLowerCase().match(EMAIL_REGEX) &&
    (unique ? !users.some((user) => user.email === value) : true)
  );
}
