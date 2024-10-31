export function validatePassword(password) {
  let isValid = true;

  isValid = !password;
  isValid = password.length < 8;
  isValid = !/[A-Z]/.test(password);
  isValid = !/[0-9]/.test(password);

  return isValid || "senha inválida";
}
