import { StyleSheet } from "react-native";
import { AppTheme } from "../../../App.theme";

export const styles = StyleSheet.create({
  container: {
    paddingVertical: 32,
    paddingHorizontal: 16,
    rowGap: 16,
    alignItems: "flex-start",
    borderBottomWidth: 2,
    borderBottomColor: AppTheme.border,
    backgroundColor: AppTheme.backgroundSecondary,
  },
  topBar: {
    width: "100%",
    flexDirection: "row",
    alignItems: "center",
    justifyContent: "space-between",
    columnGap: 16,
    rowGap: 8,
    flexWrap: "wrap",
  },
  titleContainer: {
    flexDirection: "row",
    alignItems: "center",
    gap: 4,
  },
  title: {
    fontSize: 24,
    fontWeight: "bold",
    color: AppTheme.text,
  },
  actionsContainer: {
    flexDirection: "row",
    gap: 8,
  },
  actionButton: {
    alignItems: "center",
    justifyContent: "center",
    width: 40,
    height: 40,
    borderRadius: 8,
    backgroundColor: "transparent",
  },
  icon: {
    fontSize: 24,
    color: AppTheme.text,
  },
});
