import { StyleSheet } from "react-native";
import { AppTheme } from "../../App.theme";

export const styles = StyleSheet.create({
  container: {
    position: "absolute",
    bottom: 32,
    alignItems: "center",
    width: "100%",
    paddingTop: 3,
  },
  contentContainer: {
    flexDirection: "row",
    alignItems: "center",
    justifyContent: "center",
    borderRadius: 8,
    overflow: "hidden",
  },
  tabButton: {
    alignItems: "center",
    justifyContent: "center",
    width: 100,
    height: 60,
    paddingVertical: 8,
    paddingHorizontal: 16,
    borderTopWidth: 3,
    borderTopColor: AppTheme.button,
    backgroundColor: AppTheme.button,
  },
  selected: {
    borderColor: AppTheme.accent,
    backgroundColor: AppTheme.black,
  },
  icon: {
    fontSize: 24,
    color: AppTheme.text,
  },
  divider: {
    width: 1,
    height: "100%",
    backgroundColor: AppTheme.border,
  },
});
