import { APP_COLORS, APP_TYPOGRAPHY } from "@/assets/theme";
import { StyleSheet } from "react-native";

export const styles = StyleSheet.create({
  headerContainer: {
    justifyContent: "flex-end",
  },
  title: {
    ...APP_TYPOGRAPHY.largeTitle,
    color: APP_COLORS.darkBlue,
    textAlign: "center",
  },
  settingsContainer: {
    marginTop: 32,
    marginBottom: 64,
    alignItems: "flex-start",
    gap: 12,
  },
  score: {
    ...APP_TYPOGRAPHY.mediumText,
    color: APP_COLORS.white,
  },
  tip: {
    ...APP_TYPOGRAPHY.largeText,
    color: APP_COLORS.white,
    textAlign: "center",
    paddingHorizontal: 12,
  },
  avatarContainer: {
    alignItems: "center",
    justifyContent: "center",
    width: 40,
    height: 40,
    borderRadius: 100,
    paddingVertical: 8,
    paddingHorizontal: 10,
    borderWidth: 1,
    borderColor: APP_COLORS.darkBlue,
  },
  avatar: {
    width: "100%",
  },
  label: {
    ...APP_TYPOGRAPHY.largeText,
    color: APP_COLORS.darkBlue,
    flexGrow: 1,
  },
  button: {
    flexDirection: "row",
    alignItems: "center",
    gap: 20,
    justifyContent: "flex-start",
  },
  logo: {
    height: 32,
  },
  versionContainer: {
    justifyContent: "center",
    alignItems: "center",
    gap: 8,
  },
  version: {
    ...APP_TYPOGRAPHY.largeText,
    color: APP_COLORS.blueishGray,
  },
});
