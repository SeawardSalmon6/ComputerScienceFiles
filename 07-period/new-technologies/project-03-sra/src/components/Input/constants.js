export const getInputProps = ({ type }) => {
  if (type === "password") {
    return {
      autoCapitalize: "none",
      autoCorrect: false,
      autoComplete: "password",
      textContentType: "password",
      secureTextEntry: true,
    };
  }

  if (type === "email") {
    return {
      autoCapitalize: "none",
      autoCorrect: false,
      autoComplete: "email",
      textContentType: "emailAddress",
      keyboardType: "email-address",
    };
  }

  return {};
};
