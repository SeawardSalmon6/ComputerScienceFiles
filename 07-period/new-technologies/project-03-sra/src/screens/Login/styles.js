import { APP_COLORS, APP_TYPOGRAPHY } from "@/assets/theme";
import { StyleSheet } from "react-native";

export default StyleSheet.create({
  linksContainer: {
    alignSelf: "center",
    gap: 8,
    marginTop: 6,
    marginBottom: 52,
  },
  link: {
    ...APP_TYPOGRAPHY.smallText,
    paddingVertical: 4,
    textAlign: "center",
    color: APP_COLORS.darkBlue,
  },
});
