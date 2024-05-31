import { StyleSheet } from "react-native";
import { AppTheme } from "../../../App.theme";

export const styles = StyleSheet.create({
  inputContainer: {
    gap: 24,
  },
  titleContainer: {
    marginTop: 32,
  },
  uploadContainer: {
    gap: 4,
  },
  image: {
    width: "100%",
    height: 100,
    borderRadius: 8,
  },
  buttonContainer: {
    marginTop: 32,
    alignItems: "flex-end",
  },
  button: {
    paddingVertical: 12,
    paddingHorizontal: 24,
    borderRadius: 8,
    backgroundColor: AppTheme.accent,
  },
  buttonText: {
    color: AppTheme.text,
    fontWeight: "500",
    fontSize: 16,
  },
});
