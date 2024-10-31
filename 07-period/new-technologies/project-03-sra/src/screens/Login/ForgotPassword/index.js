import { Button } from "@/components/Button";
import { Form } from "@/components/Form";
import { Input } from "@/components/Input";
import { LoginLayout } from "@/screens/Login/components/LoginLayout";
import { isAllFieldsFilled } from "@/utils/isAllFieldsFilled";
import { useState } from "react";
import { Controller, useForm } from "react-hook-form";

const FORM_FIELDS = ["email"];

export function ForgotPasswordScreen() {
  const [isButtonDisabled, setIsButtonDisabled] = useState(true);

  const { watch, control } = useForm();
  watch((values) => {
    setIsButtonDisabled(!isAllFieldsFilled(values ?? {}, FORM_FIELDS));
  });

  return (
    <LoginLayout
      title="vamos criar outra senha"
      subtitle="primeiro confirme seu e-mail"
    >
      <Form>
        <Controller
          control={control}
          name="email"
          render={({ field: { value, onChange } }) => (
            <Input
              type="email"
              label="e-mail"
              value={value}
              onChange={onChange}
            />
          )}
        />
        <Button disabled={isButtonDisabled}>continuar</Button>
      </Form>
    </LoginLayout>
  );
}
