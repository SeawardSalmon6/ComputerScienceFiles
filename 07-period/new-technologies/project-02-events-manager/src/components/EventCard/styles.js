import { StyleSheet } from "react-native";
import { AppTheme } from "../../App.theme";

export const styles = StyleSheet.create({
  container: {
    width: "100%",
  },
  image: {
    width: "100%",
    height: 100,
    borderTopLeftRadius: 8,
    borderTopRightRadius: 8,
  },
  contentContainer: {
    position: "relative",
    gap: 16,
    paddingTop: 12,
    paddingHorizontal: 16,
    paddingBottom: 20,
    borderBottomStartRadius: 12,
    borderBottomEndRadius: 12,
    backgroundColor: AppTheme.backgroundSecondary,
  },
  infoContainer: {
    alignItems: "flex-start",
    justifyContent: "flex-start",
  },
  dateContainer: {
    flexDirection: "row",
    alignItems: "center",
    justifyContent: "space-between",
    width: "100%",
  },
  actionsContainer: {
    position: "absolute",
    top: -6,
    right: -6,
  },
  actionContainer: {
    paddingHorizontal: 12,
    paddingVertical: 12,
  },
  icon: {
    fontSize: 20,
  },
  date: {
    maxWidth: "80%",
    fontSize: 14,
    lineHeight: 21,
    fontWeight: "600",
    color: AppTheme.accent,
  },
  title: {
    marginTop: 4,
    fontSize: 20,
    lineHeight: 30,
    fontWeight: "600",
    color: AppTheme.title,
  },
  location: {
    fontSize: 16,
    lineHeight: 24,
    color: AppTheme.textLight,
  },
  tagsContainer: {
    flexDirection: "row",
    flexWrap: "wrap",
    gap: 8,
  },
  tag: {
    paddingVertical: 4,
    paddingHorizontal: 8,
    borderRadius: 4,
    fontSize: 14,
    color: AppTheme.text,
    fontWeight: "600",
  },
  available: {
    backgroundColor: AppTheme.available,
  },
  availableTickets: {
    backgroundColor: AppTheme.availableTickets,
  },
  info: {
    backgroundColor: AppTheme.highlight,
  },
  warning: {
    backgroundColor: AppTheme.warning,
  },
  soldOut: {
    backgroundColor: AppTheme.soldOut,
  },
  emptyContainer: {
    alignItems: "center",
    justifyContent: "center",
    height: 120,
    padding: 20,
    borderWidth: 1,
    borderStyle: "dashed",
    borderRadius: 12,
    borderColor: AppTheme.textLight,
  },
  emptyText: {
    fontSize: 16,
    color: AppTheme.textLight,
    textAlign: "center",
  },
});
