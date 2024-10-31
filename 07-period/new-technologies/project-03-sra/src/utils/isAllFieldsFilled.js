export function isAllFieldsFilled(values, fields) {
  if (!values || !fields) {
    return true;
  }

  return fields.every((field) => {
    const [fieldName, validator] =
      typeof field === "string" ? [field, Boolean] : field;
    const value = values[fieldName];
    return validator(value);
  });
}
