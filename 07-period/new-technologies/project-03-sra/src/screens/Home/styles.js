import { APP_COLORS, APP_TYPOGRAPHY } from "@/assets/theme";
import { StyleSheet } from "react-native";

export const styles = StyleSheet.create({
  headerContainer: {
    marginBottom: 32,
  },
  cardContainer: {
    paddingVertical: 64,
    paddingHorizontal: 32,
  },
  cardContentContainer: {
    alignItems: "center",
    gap: 20,
  },
  icon: {
    width: 60,
  },
  titleContainer: {
    alignItems: "center",
    gap: 4,
  },
  title: {
    ...APP_TYPOGRAPHY.subtitle,
    color: APP_COLORS.white,
  },
  score: {
    ...APP_TYPOGRAPHY.mediumText,
    color: APP_COLORS.white,
  },
  tip: {
    ...APP_TYPOGRAPHY.largeText,
    color: APP_COLORS.white,
    textAlign: "center",
    maxWidth: "80%",
  },
});
