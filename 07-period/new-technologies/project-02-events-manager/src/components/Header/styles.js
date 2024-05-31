import { StyleSheet } from "react-native";
import { AppTheme } from "../../App.theme";

export const styles = StyleSheet.create({
  container: {
    position: "relative",
    alignItems: "flex-start",
    marginBottom: 32,
  },
  title: {
    fontSize: 24,
    color: AppTheme.title,
  },
  h1: {
    fontSize: 24,
  },
  h2: {
    fontSize: 20,
  },
  divider: {
    position: "absolute",
    bottom: -8,
    maxWidth: "100%",
    height: 1,
    backgroundColor: AppTheme.accent,
    borderRadius: 8,
  },
});
