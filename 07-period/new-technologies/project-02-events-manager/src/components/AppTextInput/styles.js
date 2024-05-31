import { StyleSheet } from "react-native";
import { AppTheme } from "../../App.theme";

export const styles = StyleSheet.create({
  inputContainer: {
    width: "100%",
  },
  inputWrapper: {
    position: "relative",
  },
  input: {
    paddingVertical: 8,
    paddingHorizontal: 16,
    borderRadius: 8,
    fontSize: 16,
    backgroundColor: AppTheme.black,
    borderWidth: 1,
    borderColor: AppTheme.border,
    color: AppTheme.text,
  },
  inputWithSuffix: {
    paddingRight: 48,
  },
  suffix: {
    position: "absolute",
    top: 4,
    right: 6,
    justifyContent: "center",
    alignItems: "center",
    padding: 8,
    backgroundColor: "transparent",
    color: AppTheme.placeholder,
  },
  textarea: {
    verticalAlign: "top",
    paddingVertical: 16,
  },
});
