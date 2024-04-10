import { View } from "react-native";
import { AppHeader } from "../../components/AppHeader";

export function ScreenA() {
  return (
    <AppHeader
      title="Screen A"
      redirectTo={{ path: "screen_b", title: "Screen B" }}
    />
  );
}
