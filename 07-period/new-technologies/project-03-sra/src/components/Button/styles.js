import { APP_COLORS, APP_TYPOGRAPHY } from "@/assets/theme";
import { StyleSheet } from "react-native";

export default StyleSheet.create({
  button: {
    alignItems: "center",
    justifyContent: "center",
    paddingVertical: 14,
    paddingHorizontal: 18,
    borderRadius: 30,
    backgroundColor: APP_COLORS.darkBlue,
  },
  buttonText: {
    ...APP_TYPOGRAPHY.subtitle,
    color: APP_COLORS.white,
  },
  disabled: {
    opacity: 0.5,
  },
});
