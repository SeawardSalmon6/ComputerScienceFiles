import { APP_COLORS, APP_TYPOGRAPHY } from "@/assets/theme";
import { StyleSheet } from "react-native";

export default StyleSheet.create({
  container: {
    paddingVertical: 32,
    paddingHorizontal: 40,
    borderRadius: 30,
    elevation: 2,
    width: "100%",
  },
  title: {
    ...APP_TYPOGRAPHY.title,
    color: APP_COLORS.darkBlue,
  },
  subtitle: {
    ...APP_TYPOGRAPHY.mediumText,
    color: APP_COLORS.darkBlue,
  },
  titleContainer: {
    alignItems: "flex-start",
  },
});
